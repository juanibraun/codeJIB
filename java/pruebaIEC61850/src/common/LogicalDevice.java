/*
 * Copyright Fraunhofer ISE, energy & meteo Systems GmbH, and other contributors 2011
 *
 * This file is part of openIEC61850.
 * For more information visit http://www.openmuc.org 
 *
 * openIEC61850 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * openIEC61850 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with openIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
package common;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;

public final class LogicalDevice extends ModelNode {

	public LogicalDevice(ObjectReference objectReference, List<LogicalNode> logicalNodes) {
		children = new LinkedHashMap<String, ModelNode>();
		this.objectReference = objectReference;
		for (LogicalNode logicalNode : logicalNodes) {
			this.children.put(logicalNode.getReference().getName(), logicalNode);
		}
	}

	@Override
	public LogicalDevice copy() {
		List<LogicalNode> childCopies = new ArrayList<LogicalNode>(children.size());
		for (ModelNode childNode : children.values()) {
			childCopies.add((LogicalNode) childNode.copy());
		}
		return new LogicalDevice(objectReference, childCopies);
	}

}